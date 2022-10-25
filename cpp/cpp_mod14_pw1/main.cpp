//#include <iostream>

int main() {                     /*  fork  spoon knife plate chair   */
                                 /*    |     |     |     |     |     */
    int packFirstRow[5][5] =  {{1,1,1,1,1},
                               {1,1,1,1,1},
                               {1,1,1,1,1},
                               {1,1,1,1,1},
                               {1,1,1,1,1}};

    int packSecondRow[5][5] = {{1,1,1,1,1},
                               {1,1,1,1,1},
                               {1,1,1,1,1},
                               {1,1,1,1,1},
                               {1,1,1,1,1}};

                           /*                    small      dessert         */
                           /*  fork  spoon knife spoon plate plate chair    */
                           /*    |     |     |     |     |     |     |      */
    int packVIP[2][7] = {{1,1,1,1,1,1,1},
                         {1,1,1,1,1,1,1}};

    /*Event scenario:***************************/
    /*The lady brought the child with her to the fifth place of the first row*/
    packFirstRow[4][4] += 1;

    /*A spoon was stolen from the third seat in the second row.*/
    packSecondRow[2][1] -= 1;

    /*VIP shared his spoon*/
    packVIP[0][1] -= 1;
    packSecondRow[2][1] += 1;

    /*The waiter stole a dessert plate from a VIP guest.
     * Scoundrel! Looks like he stole the spoon from third place in the second row...*/
    packVIP[0][5] -= 1;

    return 0;
}
