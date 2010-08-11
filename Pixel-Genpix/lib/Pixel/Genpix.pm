# This file was automatically generated by SWIG (http://www.swig.org).
# Version 2.0.0
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

package Pixel::Genpix;
use base qw(Exporter);
use base qw(DynaLoader);
package Pixel::Genpixc;
bootstrap Pixel::Genpix;
package Pixel::Genpix;
@EXPORT = qw();

# ---------- BASE METHODS -------------

package Pixel::Genpix;

sub TIEHASH {
    my ($classname,$obj) = @_;
    return bless $obj, $classname;
}

sub CLEAR { }

sub FIRSTKEY { }

sub NEXTKEY { }

sub FETCH {
    my ($self,$field) = @_;
    my $member_func = "swig_${field}_get";
    $self->$member_func();
}

sub STORE {
    my ($self,$field,$newval) = @_;
    my $member_func = "swig_${field}_set";
    $self->$member_func($newval);
}

sub this {
    my $ptr = shift;
    return tied(%$ptr);
}


# ------- FUNCTION WRAPPERS --------

package Pixel::Genpix;


############# Class : Pixel::Genpix::Genpix ##############

package Pixel::Genpix::Genpix;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( Pixel::Genpix );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = Pixel::Genpixc::new_Genpix(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        Pixel::Genpixc::delete_Genpix($self);
        delete $OWNER{$self};
    }
}

*save = *Pixel::Genpixc::Genpix_save;
*version = *Pixel::Genpixc::Genpix_version;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : Pixel::Genpix::Vec ##############

package Pixel::Genpix::Vec;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( Pixel::Genpix );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = Pixel::Genpixc::new_Vec(@_);
    bless $self, $pkg if defined($self);
}

*size = *Pixel::Genpixc::Vec_size;
*empty = *Pixel::Genpixc::Vec_empty;
*clear = *Pixel::Genpixc::Vec_clear;
*push = *Pixel::Genpixc::Vec_push;
*pop = *Pixel::Genpixc::Vec_pop;
*get = *Pixel::Genpixc::Vec_get;
*set = *Pixel::Genpixc::Vec_set;
sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        Pixel::Genpixc::delete_Vec($self);
        delete $OWNER{$self};
    }
}

sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : Pixel::Genpix::Array ##############

package Pixel::Genpix::Array;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( Pixel::Genpix );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = Pixel::Genpixc::new_Array(@_);
    bless $self, $pkg if defined($self);
}

*size = *Pixel::Genpixc::Array_size;
*empty = *Pixel::Genpixc::Array_empty;
*clear = *Pixel::Genpixc::Array_clear;
*push = *Pixel::Genpixc::Array_push;
*pop = *Pixel::Genpixc::Array_pop;
*get = *Pixel::Genpixc::Array_get;
*set = *Pixel::Genpixc::Array_set;
sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        Pixel::Genpixc::delete_Array($self);
        delete $OWNER{$self};
    }
}

sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


# ------- VARIABLE STUBS --------

package Pixel::Genpix;

*GENPIX_VERSION = *Pixel::Genpixc::GENPIX_VERSION;
1;
