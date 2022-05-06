#ifndef STANDARD_TYPE_H
#define STANDARD_TYPE_H

/* Define return type of function */
typedef int Std_ReturnType;
#define E_OK            0x00
#define E_NOT_OK        0x01

/* Define null poiner */
#define NULL_PTR        NULL

/* Define turn on/off feature type */
#define STD_ON                 (1U)
#define STD_OFF                (0U)

/* Define check parameter of function */
#define CHECK_PARAMETER(x)     if(x) {} else { while(1); }

#endif /* STANDARD_TYPE_H */