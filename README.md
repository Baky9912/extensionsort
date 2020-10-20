# extensionsort

Sorts by extensions and deletes empty directories. It will not change directories you already have in that directory if they are not empty.

`sh setup.sh` to install

Test your build by running testsetup.sh and then `extensionsort testdir`. The testdir directory should be sorted now

`extensionsort <path to directory>` to sort a directory once

Run `crontab -e` and append `* * * * * extensionsorter <path to directory>` to keep a directory sorted.
