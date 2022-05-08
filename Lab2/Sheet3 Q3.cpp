set state = NORMAL;
set state1 = TIME;
set m = 0, h = 0, D = 1, M = 1, Y = 2000.
        For each input do
    switch (state)
        Case NORMAL : {
            If(input == c) 
                state = UPDATE
            If(input == b) 
                state = ALARM
            If(input == a)
                If(state1 == TIME)
                state1 = DATE
            else
                state1 = TIME
            }
Case UPDATE :
{
    int count = 0;
    while (count != 5) {
        if (input == a) {
            count++;
        }
        if (input == b) {
            if (count == 0) {
                if (m60 != 59) {
                    m60++;
                }

                elseif(m60 == 59) {
                    m60 = 0;
                }


            }
            if (count == 1) {
                if (h != 23) {
                    h24++;
                }

                elseif(h == 23) {
                    h24 = 0;
                }

            }
            if (count == 2) {

                if (D31 != 31 && (M12 != 2 || M12 != 4 || M12 != 6 || M12 != 9 || M12 != 11)) {
                    D31++;
                }

                elseif(D31 == 31) {
                    D31 = 1;
                }
                if (M12 == 2 && D31 != 28) {
                    D31++;
                }

                elseif(M12 == 2 && D31 == 28) {
                    D31 = 1;
                }
                if ((M12 == 4 || M12 == 6 || M12 == 9 || M12 == 12) && D31 != 30) {
                    D31++;
                } else if (D31 == 30) {
                    D31 = 1;

                }
            }
            if (count == 3) {
                if (M12 != 12) {
                    M12++;
                } else if (M12 == 12) {
                    M12 = 1;
                }
                if (count == 4) {
                    Y++;
                }


            }
            if (input == d) {
                state = normal;
            }
        }
        if (count == 5) {
            state = normal;
        }
    }
    Case ALARM :{
        int count = 0;
        while (count != 2 && input != D) {
            if (input == b) {
                count++;
            } else if (input == c) {
                if (count = 0) {
                    if (mA60 == 60) {
                        mA60 = 1
                    } else
                        mA60++;
                }
                `if (count = 1) {
                    if (hA24 == 23) {
                        hA24 = 0
                    } else
                        hA24++;
                }
                if (count == 2) {
                    state = normal
                }
            }
            if (input == d) {
                state = normal;
            }
        }
        if (input == a) {
            ring()
        }}
    DisplayDate(){print Y + "-" + M + "-" + D}
    DisplayTIME(){print h + ":" + m}