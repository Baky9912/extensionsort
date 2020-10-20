# extensionsort

Sorts by extensions and deletes empty directories. It will not change directories you already have in that directory if they are not empty.

sh setup.sh to install

extensionsort <directory_path> to sort a directory once

Test your build by running usetup.sh and then extensionsort testdir

Run `crontab -e` and append `* * * * * extensionsorter <path to directory>` to keep a directory sorted.

~/Downloads

|-a.pdf

|-b.pdf

|-c.txt

|-d.txt

| e

| |-f.py

|-g

extensionsorter ~/Downloads

~/Downloads

| pdf

| |-a.pdf

| |-b.pdf

| txt

| |-c.txt

| |-d.txt

| e

| |-f.py

| plain

| |-g
