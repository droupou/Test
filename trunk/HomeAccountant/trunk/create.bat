#!/usr/bin/perl -w	
#Use Perl with warnings

#my $hst = "localhost";
my $hst = "gandalf";

print "Connecting to $hst.\n";

#clear

system("createdb --echo --host=$hst --username=postgres homeaccount");
system("createlang --dbname=homeaccount --host=$hst --username=postgres plpgsql");
system("psql -q -d homeaccount -f database.sql -h $hst -U postgres");

