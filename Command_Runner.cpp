#include "Command_Runner.h"
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
double benchmark(int algorithmIndex, int a[], int n)
{
    auto start = chrono::high_resolution_clock::now();
    RunSortAlgorithm(algorithmIndex, a, n);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}
double benchmark(int algorithmIndex, int a[], int n,long long &comp)
{
    auto start = chrono::high_resolution_clock::now();
    RunSortComparison(algorithmIndex, a, n,comp);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}
static void RunA1(const Command &command)
{
    cout << "ALGORITHM MODE\n";
    cout << "Command 1\n";
    cout << "Algorithm: " << command.algorithm_1 << "\n";
    cout << "Input file: " << command.inputfile << "\n";
    cout << "Output parameter: " << command.output_param << "\n";

    // TODO:
    int OutputIndex = GetOutputParamIndex(command.output_param);

    long long comp;
    double running_time;
    ifstream fin(command.inputfile);
    if(!fin.is_open()){
        cout << "ko mo dc ";
        return ;
    }
    int n;
    fin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        fin >> a[i];
    
    int x = GetAlgorithmIndex(command.algorithm_1);
    if(OutputIndex == 0) running_time = benchmark(x, a, n);
    if(OutputIndex == 1)     RunSortComparison(x, a, n, comp);
    if(OutputIndex == 2 ) {
        running_time = benchmark(x,a,n,comp);
    }
    ofstream fout("output.txt");
    cout << "----------" << endl;

    for (int i = 0; i < n; i++)
        fout << a[i] << ' ';
    delete[] a;
    fout.close();
    fin.close();
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

    // TODO:
    // Generate data
    // Write input.txt
    // Call sort
    // Write output.txt
}

static void RunA3(const Command &command)
{
    cout << "ALGORITHM MODE\n";
    cout << "Command 3\n";
    cout << "Algorithm: " << command.algorithm_1 << "\n";
    cout << "Input size: " << command.inputsize << "\n";
    cout << "Output parameter: " << command.output_param << "\n";

    // TODO:
    // Generate 4 cases
    // Write input_1.txt, input_2.txt, input_3.txt, input_4.txt
}

static void RunC4(const Command &command)
{
    cout << "COMPARISON MODE\n";
    cout << "Command 4\n";
    cout << "Algorithm 1: " << command.algorithm_1 << "\n";
    cout << "Algorithm 2: " << command.algorithm_2 << "\n";
    cout << "Input file: " << command.inputfile << "\n";

    // TODO:
    // Read file
    // Copy array
    // Compare 2 algorithms
}

static void RunC5(const Command &command)
{
    cout << "COMPARISON MODE\n";
    cout << "Command 5\n";
    cout << "Algorithm 1: " << command.algorithm_1 << "\n";
    cout << "Algorithm 2: " << command.algorithm_2 << "\n";
    cout << "Input size: " << command.inputsize << "\n";
    cout << "Input order: " << command.inputOrder << "\n";

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