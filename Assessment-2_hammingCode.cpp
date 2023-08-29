#include <iostream>
// #include <bit_xor>
using namespace std;

int main()
{
    int n;
    cout << "Number of Bits: ";
    cin >> n;
    cout << "Enter the Sender Data: ";
    int sender_data[n];

    for (int i = n - 1; i >= 0; i--)
    {
        cin >> sender_data[i];
    }
    // Formula for Calulating the Parity
    int p1_sender = sender_data[0] xor sender_data[1] xor sender_data[3] xor sender_data[4] xor sender_data[6];
    int p2_sender = sender_data[0] xor sender_data[2] xor sender_data[3] xor sender_data[5] xor sender_data[6];
    int p3_sender = sender_data[1] xor sender_data[2] xor sender_data[3] xor sender_data[7];
    int p4_sender = sender_data[4] xor sender_data[5] xor sender_data[6] xor sender_data[7];

    cout << "Enter the Receiver Data: ";

    int receiver_data[n];
    for (int i = n - 1; i >= 0; i--)
    {
        cin >> receiver_data[i];
    }

    int p1_receiver = receiver_data[0] xor receiver_data[1] xor receiver_data[3] xor receiver_data[4] xor receiver_data[6];
    int p2_receiver = receiver_data[0] xor receiver_data[2] xor receiver_data[3] xor receiver_data[5] xor receiver_data[6];
    int p3_receiver = receiver_data[1] xor receiver_data[2] xor receiver_data[3] xor receiver_data[7];
    int p4_receiver = receiver_data[4] xor receiver_data[5] xor receiver_data[6] xor receiver_data[7];

    int bit1 = p1_receiver xor p1_sender;
    int bit2 = p2_receiver xor p2_sender;
    int bit3 = p3_receiver xor p3_sender;
    int bit4 = p4_receiver xor p4_sender;

    int result = bit4 * (8) + bit3 * (4) + bit2 * (2) + bit1 * (1);
    int error_position = -1;
    int parityPosition = -1;

    cout << "CodeWord at Sender Side: ";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << sender_data[i];[


            
        ]
    }
    cout << "\n";

    if (result == 1)
    {
        error_position = -2;
        parityPosition = 1;
    }

    else if (result == 2)
    {
        error_position = -2;
        parityPosition = 2;
    }

    else if (result == 3)
    {
        error_position = 1;
    }

    else if (result == 4)
    {
        error_position = -1;
        parityPosition = 3;
    }

    else if (result == 5)
    {
        error_position = 2;
    }

    else if (result == 6)
    {
        error_position = 3;
    }

    else if (result == 7)
    {
        error_position = 4;
    }

    else if (result == 8)
    {
        error_position = -1;
        parityPosition = 4;
    }

    else if (result == 9)
    {
        error_position = 5;
    }

    else if (result == 10)
    {
        error_position = 6;
    }

    else if (result == 11)
    {
        error_position = 7;
    }

    else if (result == 12)
    {
        error_position = 8;
    }

    else
    {
        error_position = -1;
        parityPosition = -1;
    }

    if (error_position == -1 && parityPosition == -1)
    {
        cout << "No Error"<< "\n";
    }
    if (parityPosition != -1)
    {
        cout << "Parity Position is wrong at position: " << parityPosition << "\n";
    }
    else
    {
        cout << "CodeWord at Receiver Side: ";
        for (int i = n - 1; i >= 0; i--)
        {
            cout << receiver_data[i];
        }
        cout << "\n";
        cout << "Error at Position: " << error_position << " from last"<< "\n";
        if (receiver_data[error_position - 1] == 1)
        {
            receiver_data[error_position - 1] = 0;
        }
        else
        {
            receiver_data[error_position - 1] = 1;
        }

        cout << "The corrected data: ";
        for (int i = n - 1; i >= 0; i--)
        {
            cout << receiver_data[i];
        }
        cout << "\n";
    }
    return 0;
}
