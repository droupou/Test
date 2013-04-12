#!/usr/bin/perl -w	
#Use Perl with warnings

#my $hst = "localhost";
#my $hst = "gandalf";
my $hst = "127.0.0.1";

system("clear");
print "Connecting to $hst.\n";

#clear

system("createdb --echo --host=$hst --username=postgres storefront");
system("createlang --dbname=storefront --host=$hst --username=postgres plpgsql");
system("psql -q -d storefront -f database.sql -h $hst -U postgres");

