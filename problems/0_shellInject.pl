#!/usr/bin/perl

print<<EOF;
XXX: I have an intentional shell inject vulnerability.

Enter a string and I will give you the md5.
EOF

my $in = <>;

print "echo -n $in | md5sum" | `sh`;
