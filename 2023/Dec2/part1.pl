use strict;
use warnings;

my $path = $ARGV[0];

open(in_file, $path)or die "File error. Input file invalid. Exiting...\n"; 
  
my $out_sum = 0;
while(<in_file>) 
{
	my $valid_game = 1;
	my $blue_sum = 0;
	my $red_sum = 0;
	my $green_sum = 0;
	my $game_num;
    if ($_ =~ /Game\s(\d+):/g)
    {
    	$game_num = $1;
    }

    while ($_ =~ /(\d+)\sblue/g) 
    {
    	if ($1 > 14)
    	{
    		$valid_game = 0;
    	}
	}
	
	while ($_ =~ /(\d+)\sred/g) 
    {
    	if ($1 > 12)
    	{
    		$valid_game = 0;
    	}
	}

	while ($_ =~ /(\d+)\sgreen/g) 
    {
    	if ($1 > 13)
    	{
    		$valid_game = 0;
    	}
	}

	if ($valid_game)
	{
		$out_sum += $game_num;
	}
} 
print "Answer: " . $out_sum . "\n";
close; 