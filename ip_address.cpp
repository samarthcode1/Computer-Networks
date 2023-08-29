#include <iostream>
#include <vector>
using namespace std;

char Classfinding(string ip_address)
{
    int i = 0;
    while (ip_address[i] != '.')
    {
        i++;
    }
    i--;
    int ip = 0, j = 1;
    while (i >= 0)
    {
        ip += (ip_address[i] - '0') * j;
        j *= 10;
        i--;
    }

    if (ip >= 1 && ip <= 126)
        return 'A';
    else if (ip >= 128 && ip <= 191)
        return 'B';
    else if (ip >= 192 && ip <= 223)
        return 'C';
    else if (ip >= 224 && ip <= 239)
        return 'D';
    else
        return 'E';
}

int main()
{
    int n;
    cout << "Enter 1 for Binary Address IP\n";
    cout << "Enter 2 for Decimal Address IP\n";
    cin >> n;
    string ip_address;
    cout << "Enter the IP address\n";
    cin >> ip_address;
    if (n == 1)
    {
        vector<string> octat(4);
        int index = 0;
        int prev = 0;
        for (int i = 0; i <= ip_address.length(); i++)
        {
            if (ip_address[i] == '.' || ip_address[i] == '\0')
            {
                string s = ip_address.substr(0,i-1);
                octat[index] = s;
                index++;
                prev = i + 1;
            }
        }
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
    else if (n == 2)
    {
        cout << "The Class for the Given IP Address is: " << Classfinding(ip_address);
    }
    return 0;
}