# Starting Off
The project is built in JetBrain's CLion IDE. You should be able to simply open the file and compile straight away. Connect your GitHub so you can make pull requests to the main branch.

# Documentation Site

[Click here](https://garrettleising.github.io/DAPPF.github.io/#/) to see our documentation website.

# User Guide

[Click here](https://github.com/zydee3/DAPPF/blob/master/USER_GUIDE.md) to see our user guide.

# Modules Task Sheet
| No.  | Module                                      |    Status     |               Who                | Completed On |
| :--: | :------------------------------------------ | :-----------: | :------------------------------: | :----------: |
| 1.   | Network Node Connect and Disconnect         |![][completed] |             Kirill               |    11/1      |
| 2.   | Documentation Site                          |![][completed] |             Garrett              |    11/1      |
| 3.   | Documentation Github (Readme)               |![][completed] |             Vincent              |    11/3      |
| 4.   | Packet Reader and Writer                    |![][completed] |             Vincent              |    10/23     |
| 5.   | Packet Compress and Decompress              |![][completed] |             Vincent              |    11/6      |
| 6.   | Packet Encrypt and Decrypt                  |![][completed] |             Anthony              |    11/2      |
| 7.   | Data Validator                              |![][completed] |         Garrett, Vincent         |    11/10     |
| 8.   | Data Cache                                  |![][incomplete]| <strike>Vincent</strike> Shishir |      -       |
| 9.   | Data Spooler                                |![][completed] | <strike>Shishir</strike> Vincent |    11/29     |
| 10.  | Predictor                                   |![][completed] |             Vincent              |    11/27     |
| 11.  | Task Pool                                   |![][completed] |         Anthony, Vincent         |    11/29     |
| 12.  | Delegates                                   |![][completed] | <strike>Shishir</strike> Vincent |    11/29     |
| 13.  | Listeners                                   |![][completed] |             Vincent              |    11/6      |
| 14.  | Handlers                                    |![][completed] |             Vincent              |    11/29     | 
| 15.  | Example Project                             |![][completed] |             Kirill               |    11/30     |
| 16.  | Combining Modules                           |![][completed] |             Vincent              |    11/30     |

# Backlog
| No.  | Date  |                 Task                  | 
| :--: | :----:|:------------------------------------: |
| 1.   | 11/29 | Need to implement semaphore or conditional lock into `task_pool` since the thread is currently busy waiting | 
| 2.   | 11/29 | Predictor association isn't being updated and needs to be fixed | 
| 3.   | 11/29 | Cache is not complete and cannot be included in the compilable |

# Known bugs
| No.  | Date  |                 Task                  | 
| :--: | :----:|:------------------------------------: |
| 1.   | 11/30 | When broadcasting to the whole network, packets will be resent by nodes that didn't originate the packet, so the `on_packet_sent` listener will trigger, which may be unexpected behavior. |
| 2.   | 11/30 | Prediction isn't properly updating the associated value. I have unit tested the remainder of the prediction module and the tests have been working. |

# Current Unit Test Results 
```
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_packet::    test_encode_numbers()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_packet::     test_encode_string()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_packet::  test_decode_exception()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_packet::      test_validation_1()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_packet::      test_validation_2()       FAILED
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_packet::     test_compression_1()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_packet::     test_compression_2()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_packet::     test_compression_3()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_packet::     test_decompression()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_packet::            test_cipher()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_packet::          test_decipher()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_task::             test_can_run()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_task::             test_execute()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_delegates::    test_if_settable()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_delegates::    test_if_callable()       SUCCESS
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_cache::             test_insert()       FAILED
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_cache::                test_get()       FAILED
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_cache::             test_delete()       FAILED
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_cache::             test_policy()       FAILED
[INFO - Tue 11.30.2021 11:57:10] TEST dappf::Testing::  unit_test_spool::                    test()       FAILED
```

#### Built using
[![](https://img.shields.io/badge/C++-92.5%25-informational?style=flat&logo=C%2B%2B&logoColor=white&color=blue)](https://www.cplusplus.com/)
[![](https://img.shields.io/badge/Python-1.9%25-informational?style=flat&logo=Python&logoColor=white&color=yellow)](https://www.python.org/)
[![](https://img.shields.io/badge/HTML-0.7%25-informational?style=flat&logo=HTML5&logoColor=white&color=orange)](https://www.w3schools.com/html/)

<!-- Status -->
[completed]: https://img.shields.io/badge/Completed-informational?style=flat&logoColor=white&color=sucess
[wip]: https://img.shields.io/badge/In%20Progress-informational?style=flat&logoColor=white&color=yellow
[incomplete]: https://img.shields.io/badge/Incomplete-informational?style=flat&logoColor=white&color=critical
[deprecated]: https://img.shields.io/badge/Deprecated-informational?style=flat&logoColor=white&color=inactive
[success]: https://img.shields.io/badge/Success-informational?style=flat&logoColor=white&color=sucess
[failure]: https://img.shields.io/badge/Failure-informational?style=flat&logoColor=white&color=critical

<!-- Packet Stuff -->
[reader]: https://img.shields.io/badge/Packet-Reader-informational?style=flat&logoColor=white&color=00cc66
[writer]: https://img.shields.io/badge/Packet-Writer-informational?style=flat&logoColor=white&color=ff4d4d
[encryption]: https://img.shields.io/badge/Packet-Encryption-informational?style=flat&logoColor=white&color=blue
[validation]: https://img.shields.io/badge/Packet-Validation-informational?style=flat&logoColor=white&color=success
[compression]: https://img.shields.io/badge/Packet-Compression-informational?style=flat&logoColor=white&color=yellow

<!-- Links -->
[packet_reader.h]: https://github.com/zydee3/DAPPF/blob/master/framework/data/packet/packet_reader.h
[packet_writer.h]: https://github.com/zydee3/DAPPF/blob/master/framework/data/packet/packet_writer.h
[on_connection_request.h]: https://github.com/zydee3/DAPPF/blob/master/framework/meta/event_listeners/on_connection_request.h
[on_connection_established.h]: https://github.com/zydee3/DAPPF/blob/master/framework/meta/event_listeners/on_connection_established.h
[on_connection_dropped.h]: https://github.com/zydee3/DAPPF/blob/master/framework/meta/event_listeners/on_connection_dropped.h
[on_packet_received.h]: https://github.com/zydee3/DAPPF/blob/master/framework/meta/event_listeners/on_packet_received.h
[on_packet_sent.h]: https://github.com/zydee3/DAPPF/blob/master/framework/meta/event_listeners/on_packet_sent.h
[example_usage_packet_reader.cpp]: https://github.com/zydee3/DAPPF/blob/master/examples/example_usage_packet_reader.cpp
[example_usage_packet_writer.cpp]: https://github.com/zydee3/DAPPF/blob/master/examples/example_usage_packet_writer.cpp
[/data/]: https://github.com/zydee3/DAPPF/blob/master/framework/data
[/meta/]: https://github.com/zydee3/DAPPF/blob/master/framework/meta
[/net/]: https://github.com/zydee3/DAPPF/blob/master/framework/net
[/security/]: https://github.com/zydee3/DAPPF/blob/master/framework/security
[packet_cipher.h]: https://github.com/zydee3/DAPPF/blob/master/framework/data/packet/packet_cipher.h
[packet_validation.h]: https://github.com/zydee3/DAPPF/blob/master/framework/data/packet/packet_validation.h
[packet_compression.h]: https://github.com/zydee3/DAPPF/blob/master/framework/data/packet/packet_compression.h
