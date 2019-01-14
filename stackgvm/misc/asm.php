#!/usr/bin/php
<?php

print_r(shell_exec('cpp -nostdinc test.asm'));
