find ../src/vm/src -type f -name '*.h' -exec cat {} + >> vm_bundle.c && find ../src/vm/src -type f -name '*.c' -exec cat {} + >> vm_bundle.c
find ../src/vm/test -type f -name '*.h' -exec cat {} + >> vm_test_bundle.c && find ../src/vm/test -type f -name '*.c' -exec cat {} + >> vm_test_bundle.c
