struct time_out {
    string current_time<100>;
};

program DAY_PROG {
    version DAY_VERS {
        time_out GETTIME(void) = 1;
    } = 1;
} = 0x23452222;