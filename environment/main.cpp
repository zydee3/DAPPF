#include <iostream>

#include "../framework/dappf.h"
#include "../framework/net/connection.h"

int main() {
    dappf::test_function();
    dappf::connection::establish("127.0.0.1", 8484);
    system("pause");
    return 0;
}
