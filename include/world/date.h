#ifndef DAtC_DATE_H
#define DAtC_DATE_H

/**
 * @brief 
 * 
 */
typedef enum weekday_t {
    WDAY_NONE = 0,

    WDAY_MONDAY,
    WDAY_TUESDAY,
    WDAY_WEDNESDAY,
    WDAY_THURSDAY,
    WDAY_FRIDAY,
    WDAY_SATURDAY,
    WDAY_SUNDAY,

    WDAY_FIRST = WDAY_MONDAY,
    WDAY_LAST = WDAY_SUNDAY,
    WDAY_COUNT = 7
} weekday_t;

typedef enum season_t {
    SEASON_NONE = 0,

    SEASON_SPRING,
    SEASON_SUMMER,
    SEASON_AUTUMN,
    SEASON_WINTER,

    SEASON_FIRST = SEASON_SPRING,
    SEASON_LAST = SEASON_WINTER,
    SEASON_COUNT = 4
} season_t;

typedef struct date_t {
    int day;
    season_t season;
    weekday_t weekday;
} date_t;

#endif