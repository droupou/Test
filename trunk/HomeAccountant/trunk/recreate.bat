#!/usr/bin/perl -w	
#Use Perl with warnings

#my $hst = "localhost";
my $hst = "gandalf";

print "$hst\n\n";

#clear

#print "WARNING!!!! This will delete any data you may have on your system.  Please use this script ONLY if you really know what you are doing!!!!.\n               --Rick\n";
#print "Are you sure you want to continue?";


system("dropdb --host=".$hst." --echo --username=postgres homeaccount");
system("./create.bat");
