/* day.x */
struct time_out {
    string current_time<64>;
};

program DAY_PROG {
    version DAY_VERS {
        time_out GETTIME(void) = 1;
    } = 1;
} = 0x20000001;