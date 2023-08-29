#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter No. of Bits of Data: ";
    cin >> n;
    int data[n];
    int i, j, k;
    cout << "Enter Data:";
    for (i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    int Receiver_From_user[n];
    cout << "Data the Receiver Data: ";
    for (i = 0; i < n; i++)
    {
        cin >> Receiver_From_user[i];
    }
    int n1;
    cout << "Enter No. of Bits in Generator Data: ";
    cin >> n1;
    int generator[n];
    cout << "Enter Generator Data: ";
    for (i = 0; i < n1; i++)
    {
        cin >> generator[i];
    }
    int padding_bit = n1 - 1;
    cout << "Total Zeros to be appended: " << padding_bit;
    for (i = n; i < n + padding_bit; i++)
    {
        data[i] = 0;
    }
    cout << "\n";
    int temp[n + padding_bit];
    for (i = 0; i < n + padding_bit; i++)
    {
        temp[i] = data[i];
    }
    cout << "Message after appending 0's :";
    for (i = 0; i < n + padding_bit; i++)
    {
        cout << temp[i];
    }
    cout << "\n";

    for (i = 0; i < n; i++)
    {
        j = 0;
        k = i;
        if (temp[k] >= generator[j])
        {
            for (j = 0, k = i; j < n1; j++, k++)
            {
                if ((temp[k] == 1 && generator[j] == 1) || (temp[k] == 0 && generator[j] == 0))
                {
                    temp[k] = 0;
                }
                else
                {
                    temp[k] = 1;
                }
            }
        }
    }

    int crc[padding_bit];
    for (i = 0, j = n; i < padding_bit; i++, j++)
    {
        crc[i] = temp[j];
    }
    cout << "CRC bits: ";
    for (i = 0; i < padding_bit; i++)
    {
        cout << crc[i];
    }
    cout << "\n";
    cout << "CodeWord data: ";
    int sender[n + padding_bit];
    int receiver[n + padding_bit];
    for (i = 0; i < n; i++)
    {
        sender[i] = data[i];
    }
    for (i = 0; i < n; i++)
    {
        receiver[i] = Receiver_From_user[i];
    }
    for (i = n, j = 0; i < n + padding_bit, j < padding_bit; i++, j++)
    {
        sender[i] = crc[j];
    }

    for (i = n, j = 0; i < n + padding_bit, j < padding_bit; i++, j++)
    {
        receiver[i] = crc[j];
    }

    for (i = 0; i < n + padding_bit; i++)
    {
        cout << sender[i];
    }
    cout << "\n";
    cout << "Receiver bits are: ";
    for (i = 0; i < n + padding_bit; i++)
    {
        cout << receiver[i];
    }
    cout << "\n";

    for (i = 0; i < n + padding_bit; i++)
    {
        temp[i] = receiver[i];
    }
    cout << endl;

    for (i = 0; i < n; i++)
    {
        j = 0;
        k = i;
        if (temp[k] >= generator[j])
        {
            for (j = 0, k = i; j < n1; j++, k++)
            {
                if ((temp[k] == 1 && generator[j] == 1) || (temp[k] == 0 && generator[j] == 0))
                {
                    temp[k] = 0;
                }
                else
                {
                    temp[k] = 1;
                }
            }
        }
    }

    cout << "Remainder: ";
    int rem[n + padding_bit];
    for (i = 0, j = 0; i < n + padding_bit; i++, j++)
    {
        rem[j] = temp[i];
    }
    for (i = 0; i < n + padding_bit; i++)
    {
        cout << rem[i];
    }
    cout << "\n";
    int error = 0;
    for (i = 0; i < n + padding_bit; i++)
    {
        if (rem[i] != 0)
        {
            error = 1;
        }
    }
    if (error == 0)
    {
        cout << "As the Remainder is 0. Hence the data from sender to sender is correct\n ";
    }
    else
    {
        cout << "As the Remainder is not 0. Hence the data from sender to sender is having some error \n ";
    }
}
