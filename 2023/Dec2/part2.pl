use strict;
use warnings;

my $path = $ARGV[0];

open(in_file, $path)or die "File error. Input file invalid. Exiting...\n"; 
  
my $out_sum = 0;
while(<in_file>) 
{
	my $blue_min = 1;
	my $red_min = 1;
	my $green_min = 1;
	my $game_power;

    while ($_ =~ /(\d+)\sblue/g) 
    {
    	if ($1 > $blue_min)
    	{
    		$blue_min = $1;
    	}
	}
	
	while ($_ =~ /(\d+)\sred/g) 
    {
    	if ($1 > $red_min)
    	{
    		$red_min = $1;
    	}
	}

	while ($_ =~ /(\d+)\sgreen/g) 
    {
    	if ($1 > $green_min)
    	{
    		$green_min = $1;
    	}
	}

	$game_power = $blue_min * $red_min * $green_min;
	$out_sum += $game_power;
} 
print "Answer: " . $out_sum . "\n";
close; 