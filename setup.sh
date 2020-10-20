make
mv extensionsorter /usr/bin
echo "*/1 * * * * extensionsorter $1" >> /var/spool/$USER
