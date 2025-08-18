//
// Created by yareach on 25. 8. 15..
//

extern void test_channel_id();
extern void test_live_state();
extern void test_live_state_parsing();
extern void test_platform();
extern void test_channel_detail();
extern void test_channel_info();
extern void test_channel_info_parsing();

void test_channel() {
    test_channel_id();
    test_live_state();
    test_live_state_parsing();
    test_platform();
    test_channel_detail();
    test_channel_info();
    test_channel_info_parsing();
}