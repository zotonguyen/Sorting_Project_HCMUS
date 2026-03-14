#include "Command_Runner.h"
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
long long comp;
double running_time;
double benchmark(int algorithmIndex, int a[], int n)
{
    auto start = chrono::high_resolution_clock::now();
    RunSortAlgorithm(algorithmIndex, a, n);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}

double benchmark(int algorithmIndex, int a[], int n, long long &comp)
{
    auto start = chrono::high_resolution_clock::now();
    RunSortComparison(algorithmIndex, a, n, comp);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}
void Command_exc(Command command, int a[], int n)
{
    comp = 0;
    running_time = 0;
    int OutputIndex = GetOutputParamIndex(command.output_param);
    int AlgorithmIndex = GetAlgorithmIndex(command.algorithm_1);
    if (OutputIndex == 0)
        running_time = benchmark(AlgorithmIndex, a, n);
    if (OutputIndex == 1)
        RunSortComparison(AlgorithmIndex, a, n, comp);
    if (OutputIndex == 2)
    {
        running_time = benchmark(AlgorithmIndex, a, n, comp);
    }
}

void Output_Print(Command command)
{
    int OutputIndex = GetOutputParamIndex(command.output_param);

    switch (OutputIndex)
    {
    case 0:
        cout << "Running Time: " << running_time << "ms";
        break;
    case 1:
        cout << "Comparisions: " << comp;
        break;
    case 2:
        cout << "Running Time: " << running_time << "ms" << endl;
        cout << "Comparisions: " << comp;
    default:
        break;
    }
}

static void RunA1(const Command &command)
{

    cout << "ALGORITHM MODE\n";
    cout << "Command 1\n";
    cout << "Algorithm: " << command.algorithm_1 << "\n";
    cout << "Input file: " << command.inputfile << "\n";
    cout << "Output parameter: " << command.output_param << "\n";
    cout << "--------------------------------------------------------" << endl;

    // TODO:
    int OutputIndex = GetOutputParamIndex(command.output_param);
    ifstream fin(command.inputfile);
    if (!fin.is_open())
    {
        cout << "ko mo dc ";
        return;
    }
    int n;
    fin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        fin >> a[i];

    Command_exc(command, a, n);
    ofstream fout("output.txt");

    for (int i = 0; i < n; i++)
        fout << a[i] << ' ';
    delete[] a;
    fout.close();
    fin.close();
    Output_Print(command);

    cout << endl
         << endl;
}

static void RunA2(const Command &command)
{

    cout << "ALGORITHM MODE\n";
    cout << "Command 2\n";
    cout << "Algorithm: " << command.algorithm_1 << "\n";
    cout << "Input size: " << command.inputsize << "\n";
    cout << "Input order: " << command.inputOrder << "\n";
    cout << "Output parameter: " << command.output_param << "\n";
    cout << "--------------------------------------------------------" << endl;
    int n = command.inputsize;
    int *a = new int[n];
    int DataGen = GetGenerateData(command.inputOrder);
    ofstream fin("input.txt");
    ofstream fout("output.txt");
    GenerateData(a, n, DataGen);
    fin << n << endl;
    for (int i = 0; i < n; i++)
        fin << a[i] << ' ';
    Command_exc(command, a, n);
    for (int i = 0; i < n; i++)
        fout << a[i] << ' ';
    delete[] a;
    Output_Print(command);
    fin.close();
    fout.close();
}

static void RunA3(const Command &command)
{
    cout << "ALGORITHM MODE\n";
    cout << "Command 3\n";
    cout << "Algorithm: " << command.algorithm_1 << "\n";
    cout << "Input size: " << command.inputsize << "\n";
    cout << "Output parameter: " << command.output_param << "\n";
    cout << "--------------------------------------------------------" << endl;

    int n = command.inputsize;
    int *a = new int[n];
    cout << "Randomize" << endl;
    // Random
    ofstream fin("input_1.txt");
    fin << n << endl;
    GenerateData(a, n, 0);
    for (int i = 0; i < n; i++)
        fin << a[i] << " ";
    Command_exc(command, a, n);
    Output_Print(command);
    cout << endl;
    fin.close();
    // Nearly Sorted
    cout << "--------------------------------------------------------" << endl;
    cout << "Nearly Sorted" << endl;
    ofstream fin1("input_2.txt");
    fin1 << n << endl;
    GenerateData(a, n, 3);
    for (int i = 0; i < n; i++)
        fin1 << a[i] << " ";
    Command_exc(command, a, n);
    Output_Print(command);
    cout << endl;
    fin1.close();
    cout << "--------------------------------------------------------" << endl;

    // Sorted
    cout << "Sorted" << endl;
    ofstream fin2("input_3.txt");
    fin2 << n << endl;
    GenerateData(a, n, 1);
    for (int i = 0; i < n; i++)
        fin2 << a[i] << " ";
    Command_exc(command, a, n);
    Output_Print(command);
    cout << endl;
    fin2.close();
    cout << "--------------------------------------------------------" << endl;

    // Reverse Data
    cout << "Reverse" << endl;
    ofstream fin3("input_4.txt");
    fin3 << n << endl;
    GenerateData(a, n, 2);
    for (int i = 0; i < n; i++)
        fin3 << a[i] << " ";
    Command_exc(command, a, n);
    Output_Print(command);
    cout << endl;
    fin3.close();
    delete[] a;
}

static void RunC4(const Command &command)
{
    cout << "COMPARISON MODE\n";
    cout << "Command 4\n";
    cout << "Algorithm 1: " << command.algorithm_1 << "\n";
    cout << "Algorithm 2: " << command.algorithm_2 << "\n";
    cout << "Input file: " << command.inputfile << "\n";
    cout << "--------------------------------------------------------" << endl;
    double running_time2 = 0;
    long long comp2 = 0;
    int alg1 = GetAlgorithmIndex(command.algorithm_1);
    int alg2 = GetAlgorithmIndex(command.algorithm_2);
    ifstream fin(command.inputfile);
    if (!fin.is_open())
        cout << "ko mo dc";
    int n;
    fin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> a[i];
    }
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    running_time = benchmark(alg1, a, n, comp);
    running_time2 = benchmark(alg2, b, n, comp2);
    int OutputIndex = GetOutputParamIndex(command.output_param);
    cout << "Running Time: " << running_time << "ms" << " | " << running_time2 << "ms" << '\n';
    cout << "Comparisions: " << comp << " | " << comp2;

    fin.close();
    delete[] a;
    delete[] b;
}

static void RunC5(const Command &command)
{
    cout << "COMPARISON MODE\n";
    cout << "Command 5\n";
    cout << "Algorithm 1: " << command.algorithm_1 << "\n";
    cout << "Algorithm 2: " << command.algorithm_2 << "\n";
    cout << "Input size: " << command.inputsize << "\n";
    cout << "Input order: " << command.inputOrder << "\n";
    cout << "--------------------------------------------------------" << endl;
    int n = command.inputsize;
    double running_time2=0;
    long long comp2;
    int *a = new int[n];
    int *b = new int[n];
    int Datatype = GetGenerateData(command.inputOrder);
    GenerateData(a, n, Datatype);
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    ofstream fout("output.txt");
    for (int i = 0; i < n; i++)
        fout << a[i] << ' ';
    fout.close();
    int alg1 = GetAlgorithmIndex(command.algorithm_1);
    int alg2 = GetAlgorithmIndex(command.algorithm_2);
     running_time = benchmark(alg1, a, n, comp);
    running_time2 = benchmark(alg2, b, n, comp2);
      cout << "Running Time: " << running_time << "ms" << " | " << running_time2 << "ms" << '\n';
    cout << "Comparisions: " << comp << " | " << comp2;
       delete[] a;
    delete[] b;
    // TODO:
    // Generate data
    // Write input.txt
    // Compare 2 algorithms
}

void PrintInvalidCommand()
{
    cout << "Sai command line.\n";
    cout << "Vi du dung:\n";
    cout << "  groupid.exe -a quick-sort input.txt -both\n";
    cout << "  groupid.exe -a quick-sort 50000 -rand -time\n";
    cout << "  groupid.exe -a quick-sort 50000 -comp\n";
    cout << "  groupid.exe -c quick-sort merge-sort input.txt\n";
    cout << "  groupid.exe -c quick-sort merge-sort 50000 -nsorted\n";
}

void RunCommand(Command &command)
{
    switch (command.cmd)
    {
    case Command_1:
        RunA1(command);
        break;
    case Command_2:
        RunA2(command);
        break;
    case Command_3:
        RunA3(command);
        break;
    case Command_4:
        RunC4(command);
        break;
    case Command_5:
        RunC5(command);
        break;
    default:
        PrintInvalidCommand();
        break;
    }
}
