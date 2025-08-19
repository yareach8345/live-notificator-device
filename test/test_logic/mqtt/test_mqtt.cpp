//
// Created by yareach on 25. 8. 18..
//

extern void test_updated_message();
extern void test_refreshed_message();
extern void test_channel_info_changed_message();
extern void test_channel_state_changed_message();
extern void test_channel_image_changed_message();

void test_mqtt() {
    test_updated_message();
    test_refreshed_message();
    test_channel_info_changed_message();
    test_channel_state_changed_message();
    test_channel_image_changed_message();
}