#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>
using namespace std;

bool networkLoss()
{
    return (rand() % 2) == 0;
}

void transmissionDelay()
{
    this_thread::sleep_for(chrono::seconds(2));
}

void receiveACK(int sequenceNumber)
{
    cout << "Receiver: Receiving ACK for packet with Sequence number: " << sequenceNumber << "\n";
    transmissionDelay();
    if (networkLoss())
    {
        cout << "Receiver: ACK is lost!"
             << "\n";
        return;
    }
    cout << "Receiver: ACK sent back to sender!"
         << "\n";
}

void sendPacket(int sequenceNumber, const string &packetData)
{
    cout << "Sender: Sending the Packet with Sequence number: " << sequenceNumber << "\n";
    transmissionDelay();
    if (networkLoss())
    {
        cout << "Sender: Packet is lost!"
             << "\n";
        return;
    }
    cout << "Sender: Packet received at receiver!"
         << "\n";
}

int main()
{
    int sequenceNumber = 0;
    string packetData = "Sending to Receiver";
    while (true)
    {
        sendPacket(sequenceNumber, packetData);
        auto start_time = chrono::steady_clock::now();
        while (true)
        {
            auto end_time = chrono::steady_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);

            if (duration >= chrono::seconds(10))
            {
                cout << "Sender: Timeout occurred. Resending packet with sequenceNumber : " << sequenceNumber << "\n";
                break;
            }
            receiveACK(sequenceNumber);
            if (networkLoss())
            {
                cout << "Sender: ACK lost. Resending packet with sequenceNumber:" << sequenceNumber << "\n";
                break;
            }
            sequenceNumber++;
            break;
        }
        if (sequenceNumber > 10)
        {
            break;
        }
    }
    return 0;
}

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
int main(int argc, char const *argv[])
{
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    int buffer[1024] = {0};
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }
    if ((status = connect(client_fd, (struct sockaddr *)&serv_addr,
                          sizeof(serv_addr))) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(client_fd, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    valread = read(client_fd, buffer, 1024);
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", buffer[i]);
        sum += buffer[i];
    }
    printf("\nSum is: %d\n", sum);
    close(client_fd);
    return 0;
}