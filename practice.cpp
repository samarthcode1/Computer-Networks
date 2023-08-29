// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter the number of bits of data\n";
//     cin >> n;
//     int data[n];
//     int i, k, j;
//     cout << "Enter Data: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> data[i];
//     }
//     int receiver_data[n];
//     cout << "Receiver Data: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> receiver_data[i];
//     }
//     int n1;
//     cout << "Enter no. of bits in generattor data:";
//     cin >> n1;
//     int generator[n1];
//     cout<<"Enter the generator data:\n";
//     for (int i = 0; i < n1; i++)
//     {
//         cin >> generator[i];
//     }
//     int padding_bit = n1 - 1;
//     for (int i = n; i < n + padding_bit; i++)
//     {
//         data[i] = 0;
//     }
//     int temp[n + padding_bit];
//     for (int i = 0; i < n + padding_bit; i++)
//     {
//         temp[i] = data[i];
//     }
//     cout << "Message after appending zero\n";
//     for (int i = 0; i < n + padding_bit; i++)
//     {
//         cout << temp[i];
//     }
//     cout << "\n";
//     for (int i = 0; i < n; i++)
//     {
//         int j = 0;
//         int k = i;
//         if (temp[k] >= generator[j])
//         {
//             for (j = 0, k = i; j < n1; j++, k++)
//             {
//                 if ((temp[k] == 1 && generator[j] == 1) || (temp[k] == 0 && generator[j] == 0))
//                 {
//                     temp[k] = 0;
//                 }
//                 else
//                 {
//                     temp[k] = 1;
//                 }
//             }
//         }
//     }
//     int crc[padding_bit];
//     for (i = 0, j = n; i < padding_bit; i++, j++)
//     {
//         crc[i] = temp[j];
//     }
//     cout << "crc bits: ";
//     for (i = 0; i < padding_bit; i++)
//     {
//         cout << crc[i];
//     }
//     cout << "\n";
//     cout << "CodeWord data: ";
//     int sender[n + padding_bit];
//     int receiver[n + padding_bit];
//     for (int i = 0; i < n; i++)
//     {
//         sender[i] = data[i];
//         receiver[i] = receiver_data[i];
//     }
//     for (i = n, j = 0; i < n + padding_bit, j < padding_bit; i++, j++)
//     {
//         sender[i] = crc[j];
//         receiver[i] = crc[j];
//     }
//     for (i = 0; i < n + padding_bit; i++)
//     {
//         cout << sender[i];
//     }
//     cout << "\n";
//     cout << "Receiver bits are: ";
//     for (i = 0; i < n + padding_bit; i++)
//     {
//         cout << receiver[i];
//     }
//     cout << "\n";
//     for (int i = 0; i < n + padding_bit; i++)
//     {
//         temp[i] = receiver[i];
//     }
//     cout << endl;
//     for (int i = 0; i < n; i++)
//     {
//         int j = 0;
//         k = i;
//         if (temp[k] >= generator[j])
//         {
//             for (j = 0, k = i; j < n1; j++, k++)
//             {
//                 if ((temp[k] == 1 && generator[j] == 1) || (temp[k] == 0 && generator[j] == 0))
//                 {
//                     temp[k] = 0;
//                 }
//                 else
//                 {
//                     temp[k] = 1;
//                 }
//             }
//         }
//     }
//     cout << "Remainder: ";
//     int rem[n + padding_bit];
//     for (int i = 0, j = 0; i < n + padding_bit; i++, j++)
//     {
//         rem[j] = temp[i];
//     }
//     for (int i = 0; i < n + padding_bit; i++)
//     {
//         cout << rem[i];
//     }
//     cout << "\n";
//     int error = 0;
//     for (int i = 0; i < n + padding_bit; i++)
//     {
//         if (rem[i] != 0)
//         {
//             error = 1;
//         }
//     }
//     if (error == 0)
//     {
//         cout << "As the Remainder is 0. Hence the data from sender to sender is correct\n ";
//     }
//     else
//     {
//         cout << "As the Remainder is not 0. Hence the data from sender to sender is having some error \n ";
//     }
// }

// Hamming
// #include <iostream>
// using namespace std;
// int main()
// {
//     cout << "Ente the number of bits\n";
//     int n;
//     cin >> n;
//     int sender_bit[n];
//     cout << "Enter the senden bit data\n";
//     for (int i = n - 1; i >= 0; i--)
//     {
//         cin >> sender_bit[i];
//     }
//     int p1_sender = sender_bit[0] xor sender_bit[1] xor sender_bit[3] xor sender_bit[4] xor sender_bit[6];
//     int p2_sender = sender_bit[0] xor sender_bit[2] xor sender_bit[3] xor sender_bit[5] xor sender_bit[6];
//     int p3_sender = sender_bit[1] xor sender_bit[2] xor sender_bit[3] xor sender_bit[7];
//     int p4_sender = sender_bit[4] xor sender_bit[5] xor sender_bit[6] xor sender_bit[7];

//     cout << "Enter the Receiver Data: ";
//     int receiver_data[n];
//     for (int i = n - 1; i >= 0; i--)
//     {
//         cin >> receiver_data[i];
//     }
//     int p1_receiver = receiver_data[0] xor receiver_data[1] xor receiver_data[3] xor receiver_data[4] xor receiver_data[6];
//     int p2_receiver = receiver_data[0] xor receiver_data[2] xor receiver_data[3] xor receiver_data[5] xor receiver_data[6];
//     int p3_receiver = receiver_data[1] xor receiver_data[2] xor receiver_data[3] xor receiver_data[7];
//     int p4_receiver = receiver_data[4] xor receiver_data[5] xor receiver_data[6] xor receiver_data[7];
//     int bit1 = p1_receiver xor p1_sender;
//     int bit2 = p2_receiver xor p2_sender;
//     int bit3 = p3_receiver xor p3_sender;
//     int bit4 = p4_receiver xor p4_sender;
//     int result = bit4 * (8) + bit3 * (4) + bit2 * (2) + bit1 * (1);
//     int error_position = -1;
//     int paritypostion = -1;
//     cout << "CodeWord at Sender Side: ";
//     for (int i = n - 1; i >= 0; i--)
//     {
//         cout << sender_bit[i];
//     }
//     cout << "\n";
//     if (result == 1)
//     {
//         paritypostion = 1;
//         error_position = -2;
//     }
//     else if (result == 2)
//     {
//         paritypostion = 2;
//         error_position = -2;
//     }
//     else if (result == 3)
//     {
//         error_position = 1;
//     }
//     else if (result == 4)
//     {
//         paritypostion = 3;
//         error_position = -1;
//     }
//     else if (result == 5)
//     {
//         error_position = 2;
//     }
//     else if (result == 6)
//     {
//         error_position = 3;
//     }
//     else if (result == 7)
//     {
//         error_position = 4;
//     }
//     else if (result == 8)
//     {
//         error_position = -1;
//         paritypostion = 4;
//     }
//     else if (result == 9)
//     {
//         error_position = 5;
//     }
//     else if (result == 10)
//     {
//         error_position = 6;
//     }
//     else if (result == 11)
//     {
//         error_position = 7;
//     }
//     else if (result == 12)
//     {
//         error_position = 8;
//     }
//     else{
//         error_position=-1;
//         paritypostion=-1;
//     }
//     if(paritypostion ==-1 && error_position==-1){
//         cout<<"No Error\n";
//     }
//     if(paritypostion!=-1){
//         cout<<"Parity Position is wrong at position "<<paritypostion<<endl;
//     }
//     else{
//         cout<<"Codeword at Receiver Side: ";
//         for(int i=n-1;i>=0;i--)
//         {
//             cout<<receiver_data[i];
//         }
//         cout<<"\n";
//         cout << "Error at Position: " << error_position << " from last"<< "\n";
//         if (receiver_data[error_position - 1] == 1)
//         {
//             receiver_data[error_position - 1] = 0;
//         }
//         else
//         {
//             receiver_data[error_position - 1] = 1;
//         }

//         cout << "The corrected data: ";
//         for (int i = n - 1; i >= 0; i--)
//         {
//             cout << receiver_data[i];
//         }
//         cout << "\n";
//     }
//     return 0;
// }

//dvr
#include <iostream>
using namespace std;
struct node{
    unsigned int dist[20];
    unsigned int from[20];
}rt[10];

int main(){
    int dmat[20][20];
    int count=0,n,i,j,k;
    cout<<"Enter the number of nodes: ";
    cin >> n;
    cout<<"Enter the cost matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++)
        {
            cin>>dmat[i][j];
            dmat[i][i]=0;
            rt[i].dist[j]=dmat[i][j];
            rt[i].from[j]=j;
        }
    }
    do{
        count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j]){
                        rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                        rt[i].from[j]=k;
                        count++;
                    }
                }
            }
        }
    }while(count!=0);
    for (int i = 0; i < n; i++)
    {
        cout << "\n\nState value for router " << i + 1 << " is:\n";
        for (int j = 0; j < n; j++){
            cout<<"\n\tnode "<<j+1<<"via"<<rt[i].from[j]+1<<" Distance "<<rt[i].dist[j];
        }
        cout<<"\n\n";
    }
    return 0;

}