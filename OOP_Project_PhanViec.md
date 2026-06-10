# Phân việc nhóm — Đồ án OOP 2026: AI Agent với Ollama API

> **Nhóm:** 3 người, năng lực tương đương  
> **Bắt đầu:** Tuần 3 | **Freeze code:** Tuần 10 | **Demo:** Tuần 13  
> **Điểm thưởng target:** Multi-agent (+3đ)

---

## Phân vai 3 người

| Người | Role | Layer phụ trách |
|---|---|---|
| **A** | Systems / Core | LLMClient + AgentLoop + LoopDetector + UML |
| **B** | Tools / Data | ToolRegistry + 8 tools + MemoryTool (SQLite) |
| **C** | Eval / Infra | SkillSystem + Harness + Evaluator + Benchmark + Multi-agent |

---

## Timeline chi tiết (Tuần 3 → 12)

### Tuần 3 — Foundation & Setup

**A:**
- Setup repo GitHub, `CMakeLists.txt`, cấu trúc thư mục theo đề
- Viết abstract interface: `LLMClient.h`, `Tool.h`, `Evaluator.h` (pure virtual)
- Test kết nối Ollama từ Google Colab → gọi được `/api/chat`

**B:**
- `Tool.h` abstract class + `ToolRegistry` skeleton (đăng ký/lookup theo tên)
- Implement `CalculatorTool` + `FileTool` (read/write) — 2 tool đơn giản nhất

**C:**
- `SkillLoader` skeleton: scan thư mục `skills/`, load `.md`
- Viết 3 skill file nội dung thực (`task_planner.md`, `error_recovery.md`, 1 tự chọn)
- Setup `Trajectory` + `Step` data class

> ⚠️ **Action quan trọng tuần 3:** Cả nhóm review và **lock interface** `Tool.h`, `LLMClient.h`, `Evaluator.h` trước khi làm tiếp. Thay đổi interface sau tuần 4 sẽ break nhiều thứ.

**Commit target:** repo có structure, build được, Ollama connect được.

---

### Tuần 4 — Core loop + Tools batch 1

**A:**
- `OllamaClient` hoàn chỉnh: POST `/api/chat`, handle text + multimodal (base64 ảnh)
- Error handling: timeout, connection refused, malformed JSON
- `AgentLoop` skeleton: conversation history, max\_steps

**B:**
- `ExecTool` (chạy shell command, capture stdout/stderr)
- `WebSearchTool` (DuckDuckGo hoặc SearXNG)
- Tool policy: allow/deny list

**C:**
- `HarnessRunner` skeleton: setup → run → evaluate → record
- `KeywordEvaluator` implementation
- Viết 4 task đơn giản cho `tasks.json`

---

### Tuần 5 — ReAct loop hoàn chỉnh + Tools batch 2

**A:**
- ReAct loop đầy đủ: Observe → Think → Act → Observe
- Parse tool call từ LLM response (regex + JSON fallback)
- Inject skill vào system prompt

**B:**
- `MemoryTool` với SQLite: `memory_save` + `memory_search`
- 3 tool bổ sung từ OpenClaw (3 loại khác nhau) — chọn trước tuần 5 bắt đầu
- Test end-to-end: Agent gọi được tool thật

**C:**
- `FunctionalEvaluator`: chạy eval\_script, parse PASS/FAIL
- Trajectory recording: lưu thought/action/result/latency/tokens từng step
- 4 task trung bình cho benchmark

> ⚠️ **Điểm nguy hiểm nhất:** Tuần 5 là lần đầu 3 tầng chạy cùng nhau. Nếu interface chưa thống nhất từ tuần 3 thì sẽ bị tắc ở đây.

---

### Tuần 6 — Loop detection + Harness đầy đủ

**A:**
- `LoopDetector`: generic repeat + ping-pong, configurable threshold
- Warning vs critical log, graceful stop
- Integration test: agent chạy có loop → detect đúng

**B:**
- Polish tất cả tools: exception handling, `std::optional<T>` return
- C++17 features pass: `std::variant` cho Action type, `std::filesystem` cho SkillLoader
- Unit test từng tool

**C:**
- `HarnessRunner` hoàn chỉnh: inject `step_hook` vào AgentLoop (Observer pattern)
- Batch evaluation: chạy tập task, tính success rate
- Export JSON trajectory đúng format spec

---

### Tuần 7 — C++ modern features + Multi-agent foundation

**A:**
- C++20: concepts hoặc coroutines cho async LLM call
- C++23: `std::expected<T,E>` thay exception cho LLM errors
- C++26: 1 feature phù hợp

**B:**
- Ensure đủ 8/10 C++17 features trong bảng yêu cầu
- Smart pointer audit: không leak, `unique_ptr`/`shared_ptr` đúng chỗ
- Template `Registry<T>` generic

**C:**
- **Multi-agent foundation:** `HarnessRunner` spawn sub-agent trên thread mới
- `std::queue` + `mutex` cho message queue giữa agents
- Design test case cho 2-agent scenario

---

### Tuần 8 — Multi-agent hoàn chỉnh + 2 task khó + integration

**A:**
- Integration full pipeline: LLMClient → AgentLoop → Tool → Harness
- Refactor đảm bảo abstraction: AgentLoop không biết Harness tồn tại

**B:**
- `VLMEvaluator` (Strategy pattern — optional nhưng nên có)
- Fix bugs từ integration test tuần 7

**C:**
- Multi-agent demo: task phức tạp → chia 2 sub-agent chạy song song
- 2 task khó cho benchmark (multi-step, agent tự quyết thứ tự tool call)
- Benchmark chạy được, success rate có số

---

### Tuần 9 — UML + Báo cáo draft

**A (chủ trì UML):**
- Vẽ Class Diagram toàn hệ thống (Mermaid)
- Vẽ Sequence Diagram — 1 agent run hoàn chỉnh
- Vẽ Sequence Diagram — HarnessRunner batch evaluation
- Vẽ Component Diagram

**B:**
- Viết phần báo cáo: Tools — thiết kế, implementation, thách thức

**C:**
- Viết phần báo cáo: Benchmark/Eval — success rate, phân tích kết quả
- README: build instructions, cấu hình Ollama, run example

**A:**
- Viết phần báo cáo: Thiết kế OOP — class hierarchy, design patterns, abstraction layers

---

### Tuần 10 — Bug fix + Polish + Slide

- Full benchmark run, fix issues
- Memory leak check (Valgrind hoặc AddressSanitizer)
- Slide thuyết trình: C làm skeleton, cả nhóm review
- Rehearse demo live: thêm tool giảng viên chỉ định, giải thích design pattern

---

### Tuần 11 — Nộp design

> **Deadline: trước 21:00 Chủ nhật**

Nộp: Class Diagram + Sequence Diagram (2 cái)

---

### Tuần 12 — Nộp source + báo cáo

> **Deadline: trước 21:00 Chủ nhật**

- ZIP đúng tên: `MSSV1_MSSV2_MSSV3_OopAgent.zip`
- Đủ cấu trúc thư mục theo mục VI đề bài
- Personal Access Token cho giảng viên
- Nộp qua Moodle

---

### Tuần 13 — Demo live

Chuẩn bị demo được:
1. Khởi động Ollama từ Colab, chạy 1 agent task hoàn chỉnh từ CLI
2. Thêm tool mới (giảng viên chỉ định) vào registry và chạy lại
3. Chạy batch benchmark, show file JSON output
4. Giải thích 1 design pattern đã dùng và chỉ ra trong code

---

## Commit tracking

**Yêu cầu đề:** ≥18 commit cho nhóm 3, khoảng cách không quá 7 ngày.

| Tuần | A | B | C |
|------|---|---|---|
| 3 | repo + interfaces | ToolRegistry + 2 tools | SkillLoader + Trajectory |
| 4 | OllamaClient | ExecTool + WebTool | HarnessRunner skeleton |
| 5 | ReAct loop | MemoryTool + 3 tools | FunctionalEvaluator |
| 6 | LoopDetector | Tool polish + tests | Harness + JSON export |
| 7 | C++20/23/26 | Smart ptr audit | Multi-agent foundation |
| 8 | Integration refactor | VLMEvaluator | Multi-agent demo |
| 9 | UML + báo cáo OOP | Báo cáo Tools | README + Báo cáo Eval |
| 10 | Bug fix | Bug fix | Slide + rehearse |

**8 tuần × 3 người = 24 commit** → đủ an toàn, mỗi người ≥8 commit riêng.

---

## Checklist điểm tối đa (100đ)

### Thiết kế OOP (25đ)
- [ ] Class diagram đầy đủ, đúng UML notation
- [ ] Inheritance hierarchy hợp lý, không vi phạm LSP
- [ ] 4 design patterns đúng context: Strategy, Template Method, Registry/Factory, Observer
- [ ] Separation of concerns: AgentLoop không biết Harness

### Kỹ thuật C++ (20đ)
- [ ] ≥8/10 tính năng C++17 trong bảng yêu cầu
- [ ] Thêm ≥2 C++20, ≥2 C++23, ≥1 C++26
- [ ] Không memory leak, smart pointer đúng chỗ
- [ ] Exception handling có ý nghĩa

### Chức năng (25đ)
- [ ] 5 tool bắt buộc hoạt động đúng (exec, read/write, web\_search, memory, calculator)
- [ ] 3 tool bổ sung từ OpenClaw
- [ ] Agent loop + loop detection (2 loại)
- [ ] Skill system load và inject đúng
- [ ] Harness runner + trajectory JSON output

### Benchmark (15đ)
- [ ] 10 task hợp lệ (4 đơn giản, 4 trung bình, 2 khó)
- [ ] Evaluator chạy đúng, JSON hợp lệ
- [ ] Báo cáo success rate có phân tích

### Tài liệu (15đ)
- [ ] README: build, run, cấu hình Ollama
- [ ] Báo cáo: thiết kế, khó khăn, kết quả
- [ ] Slide thuyết trình mạch lạc

### Điểm thưởng (+3đ)
- [ ] Multi-agent: spawn sub-agent trên thread mới
- [ ] Message queue với `std::queue` + `mutex`
- [ ] Demo task phức tạp chia 2 agent song song
