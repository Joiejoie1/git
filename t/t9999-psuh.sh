#!/bin/sh

test_description='test git psuh builtin'

. ./test-lib.sh

test_expect_success 'git psuh basic functionality' '
    git psuh >output &&
    test_grep "Pony saying hello goes here." output
'

test_done
