#!/usr/bin/perl 
#____________________________________________________________________ 
# File: test.pl
#____________________________________________________________________ 
#  
# Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
# Update: 2010-07-08 13:42:11+0200
# Revision: $Id$ 
#
# Copyright: 2010 (C) Shaun ASHBY
#
#--------------------------------------------------------------------
use lib "/tmp/lib/perl5/site_perl/5.8.9/darwin-2level";

use strict;
use warnings;

use File::Basename qw(dirname);

use Astro::Source::Finder;

my $archive = dirname($0)."/t";
my $instrument = "spi_acs";
my $verbose = shift(@ARGV) || 0;

my $sf = Astro::Source::Finder::Finder->new($archive,$instrument,$verbose);
my $nrsrc = $sf->nearest(10,10,10);

print $nrsrc,"\n";
