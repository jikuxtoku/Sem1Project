#include <stdio.h>

int main() {
    // This is to certify that this project is my work based on my personal
    // efforts in studying and applying the concepts learned. I have
    // constructed the functions, their respective algorithms, and
    // corresponding code by myself. The program was run, tested, and debugged
    // by my efforts. I further certify that I have not copied in part or
    // whole or otherwise plagiarized the work of other students and/or
    // persons.
    // GENE CHRISTIAN H. CARAAN, CCC ID# 2002946
    // Last modified: 11/7/2026
    // Acknowledgements:

// LOGIN
    char name[100];
    char ch;
    int length = 0;

    char login1[30];
    int pass1;

    //MABANGIS NA LOG IN LOG OUT DELCARATION
    int isLoggedin = 2;

    //Prices
    float price1 = 950;
    float price2 = 399;
    float price3 = 250.5;
    float price4 = 89.9;

    //Item in menu and endgame ni program
    int item1, item2, item3, item4, endingPhase, doOver;

    //Summing up ng total items ordered pero seperated
    int breakdown1 = 0;
    int breakdown2 = 0;
    int breakdown3 = 0;
    int breakdown4 = 0;

    //Summing up ng total items ordered
    int totalItems = 0;
    int totalOrders = 0;

    //Total item price
    float totalitemprice1, totalitemprice2, totalitemprice3, totalitemprice4, change;


    //Final Total, summed up of everything from the cashier
    float finalTotal = 0;

    //Conditon Statements
    char isPWD;
    char tempholder;

    float subtotal;
    float vat = 0.12;
    float discount;
    float totaldiscount;
    float customergave;

    int itemsPurchased;
    float total;


    while (1) {

        while (isLoggedin == 2) {
            printf("Quasi Home Spa Service Login\n");
            printf("Enter username: ");

            scanf("%s", &login1);



            printf("Enter 4-PIN password: ");
            scanf("%d", &pass1);

            while (pass1 != 1234 && pass1 != 5678) {
                printf("Invalid password credentials, please try again.\n");
                scanf("%d", &pass1);
            }

            scanf("%*c");
            isLoggedin = 0;
        }

    while (isLoggedin == 0) {

        length = 0;

        for (int x = 0; x < 100; x++) {
            name[x] = ' ';
        }

        printf("Enter a name: ");

        while (scanf("%c", &ch) == 1) {

            if (length == 0 && (ch == ' ' || ch == '\n')) {
                if (ch == '\n') {
                    break;
                }
                continue;
            }

            if (ch == '\n') {
                break;
            }

            if (length < 100) {
                name[length] = ch;
                length++;
            }
        }


        // NOTICE: We do NOT add name[length] = '\0'; here!

        if (length == 0) {
            printf("Error: No valid input detected.\n");
        } else {
            totalOrders = 0;
            totalItems = 0;

            breakdown1 = 0;
            breakdown2 = 0;
            breakdown3 = 0;
            breakdown4 = 0;

            finalTotal = 0;

            isLoggedin = 1;

            printf("\n");
        }

    }

        //Logged in page kapag nag change yung variable na isLoggedin value to 1
        while (isLoggedin == 1) {

            printf("Username: %s\n", login1);

            printf("Welcome ");

            for (int j = 0; j < length; j++) {
            printf("%c", name[j]);
}

            printf("!");
            printf("\n==============================\n");

            printf("Body Massage (Pax) -> ");

            while (scanf("%d", &item1) != 1 || item1 < 0)
            {
                printf("Invalid input. Item must be 0 or higher.\n");
                scanf("%*c");
                printf("Item 1 -> ");
            }


            printf("Suction Cup Therapy (Pax) -> ");

            while (scanf("%d", &item2) != 1 || item2 < 0)
            {
                printf("Invalid input. Item must be 0 or higher.\n");
                scanf("%*c");
                printf("Item 2 -> ");
            }


            printf("Foot Spa (Pax) -> ");

            while (scanf("%d", &item3) != 1 || item3 < 0)
            {
                printf("Invalid input. Item must be 0 or higher.\n");
                scanf("%*c");
                printf("Item 3 -> ");
            }


            printf("Head Massage (Pax) -> ");

            while (scanf("%d", &item4) != 1 || item4 < 0)
            {
                printf("Invalid input. Item must be 0 or higher.\n");
                scanf("%*c");
                printf("Item 4 -> ");
            }

            printf("Is Senior, PWD, or Student? Y/N: ");
            scanf(" %c", &isPWD);

            while (isPWD != 'Y' && isPWD != 'N' && isPWD != 'y' && isPWD != 'n') {
                printf("Only Y/N, please try again.\n");
                printf("Is Senior, PWD, or Student?? Y/N: ");
                scanf(" %c", &isPWD);
            }

            subtotal =
                (price1 * item1) +
                    (price2 * item2) +
                        (price3 * item3) +
                            (price4 * item4);

            if (isPWD == 'Y') {
                vat = 0;
                discount = 0.15;
            } else {
                vat = 0.12;
                discount = 0;
            }

            vat = subtotal * vat;
            totaldiscount = subtotal * discount;
            total = subtotal + vat - totaldiscount;

            printf("Total: %.2f\n", total);

            printf("Customer gave: ");
            scanf("%f", &customergave);

            while (customergave < total) {
                printf("Cannot pay lower than total value. Please try again.\n");
                printf("Customer gave: ");
                scanf("%f", &customergave);
            }

            printf("\n==============================\n");
            printf("CS101 Business\n");
            printf("Calamba City Laguna\n");
            printf("Cashier Name: ");

            for (int j = 0; j < length; j++) {
                printf("%c", name[j]);
            }

            printf("\n");

            totalitemprice1 = item1 * price1;
            totalitemprice2 = item2 * price2;
            totalitemprice3 = item3 * price3;
            totalitemprice4 = item4 * price4;
            change = customergave - total;

            if (item1 > 0)printf("Body Massage x %d: %.2f\n", item1, totalitemprice1);
            if (item2 > 0)printf("Suction Cup Therapy 2 x %d: %.2f\n", item2, totalitemprice2);
            if (item3 > 0)printf("Foot Spa x %d: %.2f\n", item3, totalitemprice3);
            if (item4 > 0)printf("Head Massage x %d: %.2f\n", item4, totalitemprice4);

            printf("\nSubtotal: %.2f\n", subtotal);
            printf("VAT Amount: %.2f\n", vat);

            itemsPurchased =
                item1 +
                    item2 +
                        item3 +
                             item4;

            printf("==============================\n");
            printf("Services Provided: %d\n", itemsPurchased);
            printf("Total: %.2f\n", total);
            printf("Cash: %.2f\n", customergave);
            printf("Change: %.2f\n", change);
            printf("\n==============================\n");

            totalOrders = totalOrders + 1;
            totalItems = totalItems + item1 + item2 + item3 + item4;
            breakdown1 = breakdown1 + item1;
            breakdown2 = breakdown2 + item2;
            breakdown3 = breakdown3 + item3;
            breakdown4 = breakdown4 + item4;
            finalTotal = finalTotal + total;

            printf("1 - Another transaction\n");
            printf("2 - Logout\n");
            scanf("%d", &endingPhase);

            while (endingPhase != 1 && endingPhase != 2) {
                printf("Input not recognized.\n");
                scanf("%d", &endingPhase);
            }

            switch (endingPhase) {
                case 1:
                    break;
                case 2:
                    printf("\n==============================\n");

                    printf("Closing cash register manned by ");

                    for (int j = 0; j < length; j++) {
                        printf("%c", name[j]);
                    }

                    printf("\n");

                    printf("Total Services: %d\n", totalOrders);
                    printf("Total Services Inquired: %d\n", totalItems);
                    printf("Body Massage: %dpax\n", breakdown1);
                    printf("Suction Cup Therapy: %dpax\n", breakdown2);
                    printf("Foot Spa: %dpax\n", breakdown3);
                    printf("Head Massage: %dpax\n", breakdown4);
                    printf("Total Earnings: %.2f\n", finalTotal);

                    printf("\n==============================\n");
                    isLoggedin = 0;
                    break;

                default:
                    break;

            }


        }

        printf("1 - Login\n");
        printf("2 - Exit\n");
        scanf("%d", &doOver);

        switch (doOver) {
            case 1:
                isLoggedin = 2;
                continue;
            case 2:
                return 0;
            default:
                printf("Input not recognized.\n");
                break;
        }
    }

    return 0;
}
