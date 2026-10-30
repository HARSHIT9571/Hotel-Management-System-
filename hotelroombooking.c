#include <stdio.h>

struct Room
{
    int roomNo;
    int booked;
    char name[50];
    char phone[15];
    int days;
};

int main()
{
    struct Room room[5] = {
        {101, 0, "", "", 0},
        {102, 0, "", "", 0},
        {103, 0, "", "", 0},
        {104, 0, "", "", 0},
        {105, 0, "", "", 0}
    };

    int choice, roomNo, i;
    float bill;

    while(1)
    {
        printf("\n===== HOTEL ROOM BOOKING SYSTEM =====\n");
        printf("1. Room Booking\n");
        printf("2. Check Availability\n");
        printf("3. Cancel Booking\n");
        printf("4. Customer Details\n");
        printf("5. Bill Generation\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Room Number: ");
                scanf("%d", &roomNo);

                for(i = 0; i < 5; i++)
                {
                    if(room[i].roomNo == roomNo)
                    {
                        if(room[i].booked == 0)
                        {
                            printf("Enter Customer Name: ");
                            scanf(" %[^\n]", room[i].name);

                            printf("Enter Phone Number: ");
                            scanf("%s", room[i].phone);

                            printf("Enter Number of Days: ");
                            scanf("%d", &room[i].days);

                            room[i].booked = 1;

                            printf("Room booked successfully!\n");
                        }
                        else
                        {
                            printf("Room is already booked!\n");
                        }
                        break;
                    }
                }
                break;

            case 2:
                printf("\nRoom Availability:\n");

                for(i = 0; i < 5; i++)
                {
                    if(room[i].booked == 0)
                        printf("Room %d - Available\n", room[i].roomNo);
                    else
                        printf("Room %d - Booked\n", room[i].roomNo);
                }
                break;

            case 3:
                printf("Enter Room Number: ");
                scanf("%d", &roomNo);

                for(i = 0; i < 5; i++)
                {
                    if(room[i].roomNo == roomNo)
                    {
                        if(room[i].booked == 1)
                        {
                            room[i].booked = 0;
                            printf("Booking cancelled successfully!\n");
                        }
                        else
                        {
                            printf("Room is not booked!\n");
                        }
                        break;
                    }
                }
                break;

            case 4:
                printf("Enter Room Number: ");
                scanf("%d", &roomNo);

                for(i = 0; i < 5; i++)
                {
                    if(room[i].roomNo == roomNo && room[i].booked == 1)
                    {
                        printf("\nCustomer Name: %s\n", room[i].name);
                        printf("Phone Number: %s\n", room[i].phone);
                        printf("Room Number: %d\n", room[i].roomNo);
                        printf("Number of Days: %d\n", room[i].days);
                        break;
                    }
                }
                break;

            case 5:
                printf("Enter Room Number: ");
                scanf("%d", &roomNo);

                for(i = 0; i < 5; i++)
                {
                    if(room[i].roomNo == roomNo && room[i].booked == 1)
                    {
                        bill = room[i].days * 1000;

                        printf("\n========== BILL ==========\n");
                        printf("Customer Name: %s\n", room[i].name);
                        printf("Room Number: %d\n", room[i].roomNo);
                        printf("Days: %d\n", room[i].days);
                        printf("Total Bill: Rs. %.2f\n", bill);
                        printf("==========================\n");
                        break;
                    }
                }
                break;

            case 6:
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}