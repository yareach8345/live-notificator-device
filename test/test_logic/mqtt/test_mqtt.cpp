//
// Created by yareach on 25. 8. 18..
//

extern void test_message();
extern void test_parsing();
extern void test_mqtt_message();

void test_mqtt() {
    test_message();
    test_parsing();
    test_mqtt_message();
}