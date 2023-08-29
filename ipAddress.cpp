#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void findClass(vector<string> octat, string ip_address)
{
    if (octat[0][0] == '0')
    {
        cout << "IP Address is from Class A"
             << "\n";
    }
    if (octat[0][0] == '1' && octat[0][1] == '0')
    {
        cout << "IP Address is from Class B"
             << "\n";
    }

    if (octat[0][0] == '1' && octat[0][1] == '1' && octat[0][2] == '0')
    {
        cout << "IP Address is from Class C"
             << "\n";
    }

    if (octat[0][0] == '1' && octat[0][1] == '1' && octat[0][2] == '1' && octat[0][3] == '0')
    {
        cout << "IP Address is from Class D"
             << "\n";
    }

    if (octat[0][0] == '1' && octat[0][1] == '1' && octat[0][2] == '1' && octat[0][3] == '1' && octat[0][4] == '0')
    {
        cout << "IP Address is from Class E"
             << "\n";
    }
}

string converToBinary(int n, int bit = 8)
{
    string ip_address = "";
    while (n > 0)
    {
        int ending = n % 2;
        ip_address = to_string(ending) + ip_address;
        n = n / 2;
    }

    while (ip_address.length() != bit)
    {
        ip_address = '0' + ip_address;
    }
    return ip_address;
}

void toBinaryOctat(vector<string> &octat)
{
    int size = 4;
    for (int i = 0; i < 4; i++)
    {
        string ip_address = octat[i];
        int n = stoi(ip_address);
        octat[i] = converToBinary(n);
    }
}

void findBroadcast(vector<int> binaryInput)
{
    int first = 0;
    int second = 0;
    int third = 0;
    for (int i = 0; i < 8; i++)
    {
        first = first * 2 + binaryInput[i];
    }
    for (int i = 8; i < 16; i++)
    {
        second = second * 2 + binaryInput[i];
    }
    for (int i = 16; i < 24; i++)
    {
        third = third * 2 + binaryInput[i];
    }
    cout << "BroadCast Address: " << first << "." << second << "." << third << ".255"<< "\n";
}

void findNetwork(vector<int> binaryInput)
{
    int first = 0;
    int second = 0;
    int third = 0;
    for (int i = 0; i < 8; i++)
    {
        first = first * 2 + binaryInput[i];
    }
    for (int i = 8; i < 16; i++)
    {
        second = second * 2 + binaryInput[i];
    }
    for (int i = 16; i < 24; i++)
    {
        third = third * 2 + binaryInput[i];
    }
    cout << "Network Address: " << first << "." << second << "." << third << ".0"<< "\n";
}

int findSubnet(vector<int> binaryInput)
{
    int first = 0;
    int second = 0;
    int third = 0;
    int fourth = 0;
    for (int i = 0; i < 8; i++)
    {
        first = first * 2 + binaryInput[i];
    }
    for (int i = 8; i < 16; i++)
    {
        second = second * 2 + binaryInput[i];
    }
    for (int i = 16; i < 24; i++)
    {
        third = third * 2 + binaryInput[i];
    }
    for (int i = 24; i < 32; i++)
    {
        fourth = fourth * 2 + binaryInput[i];
    }

    cout << first << "." << second << "." << third << "." << fourth << "\n";
    return fourth;
}

void subnetAddressHelper(vector<int> binaryInput, int start, int end, string subnet, int i)
{
    vector<int> bit(32);
    for (int i = 0; i < 24; i++)
    {
        bit[i] = binaryInput[i];
    }
    for (int i = 24; i < 32; i++)
    {
        bit[i] = 0;
    }

    int subnetBits = subnet.length();
    for (int i = 0; i < subnetBits; i++)
    {
        bit[end + i] = (subnet[i] - '0');
    }
    cout << "Starting IP Address of Subnet1: " << i;
    int firstUsuable = findSubnet(bit) + 1;
    for (int i = start + 1; i < 32; i++)
    {
        bit[i] = 1;
    }

    cout << "Last IP Address of Subnet1: " << i;
    int LastUsuable = findSubnet(bit) - 1;

    int first = 0;
    int second = 0;
    int third = 0;
    for (int i = 0; i < 8; i++)
    {
        first = first * 2 + bit[i];
    }
    for (int i = 8; i < 16; i++)
    {
        second = second * 2 + bit[i];
    }
    for (int i = 16; i < 24; i++)
    {
        third = third * 2 + bit[i];
    }
    string ip = to_string(first) + '.' + to_string(second) + '.' + to_string(third) + '.';
    cout << "Usable IP Range in Subnet: "<<ip + to_string(firstUsuable) << " to "<<ip + to_string(LastUsuable);
}

void findSubnetAddress(vector<int> binaryInput, int subnetBits)
{
    int subnetsPossible = pow(2, subnetBits);
    int startIndex = 23 + subnetBits;
    int endIndex = 24;
    for (int i = 0; i < subnetsPossible; i++)
    {
        string binarySubnet = converToBinary(i, subnetBits);
        if (i == 1)
        {
            subnetAddressHelper(binaryInput, startIndex, endIndex, binarySubnet, i);
            cout << "\n";
        }
    }
}

int main()
{
    string ip_address;
    cout << "Enter IP Address: ";
    cin >> ip_address;
    vector<string> octat(4);
    int index = 0;
    int prev = 0;
    bool isDecimal = false;
    int i;
    for (i = 0; i <= ip_address.length(); i++)
    {
        if (ip_address[i] == '.' || ip_address[i] == '/')
        {
            string s = ip_address.substr(prev, i - prev);
            if (s.length() != 8)
            {
                isDecimal = true;
            }
            octat[index] = s;
            index++;
            prev = i + 1;
        }
        if (ip_address[i] == '/')
        {
            i++;
            break;
        }
    }
    int bit = 0;
    for (; i < ip_address.length(); i++)
    {
        bit = bit * 10 + (ip_address[i] - '0');
    }
    if (isDecimal)
    {
        toBinaryOctat(octat);
    }
    findClass(octat, ip_address);

    vector<int> BinaryForm(32, 0);
    index = 0;
    for (int i = 0; i < 4; i++)
    {
        string s = octat[i];
        for (int j = 0; j < 8; j++)
        {
            BinaryForm[index] = (s[j] - '0');
            index++;
        }
    }

    findBroadcast(BinaryForm);
    findNetwork(BinaryForm);
    int subnetBits = bit - 24;
    cout << "Total number of Subnets: " << pow(2, subnetBits) << "\n";
    findSubnetAddress(BinaryForm, subnetBits);
    return 0;
}