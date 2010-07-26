# This file was automatically generated by SWIG (http://www.swig.org).
# Version 2.0.0
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

package Pixel::WCS;
use base qw(Exporter);
use base qw(DynaLoader);
package Pixel::WCSc;
bootstrap Pixel::WCS;
package Pixel::WCS;
@EXPORT = qw();

# ---------- BASE METHODS -------------

package Pixel::WCS;

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

package Pixel::WCS;


############# Class : Pixel::WCS::WCS ##############

package Pixel::WCS::WCS;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( Pixel::WCS );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = Pixel::WCSc::new_WCS(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        Pixel::WCSc::delete_WCS($self);
        delete $OWNER{$self};
    }
}

*basedir = *Pixel::WCSc::WCS_basedir;
*instrument = *Pixel::WCSc::WCS_instrument;
*projections = *Pixel::WCSc::WCS_projections;
*search = *Pixel::WCSc::WCS_search;
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


############# Class : Pixel::WCS::Projections ##############

package Pixel::WCS::Projections;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( Pixel::WCS );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = Pixel::WCSc::new_Projections(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        Pixel::WCSc::delete_Projections($self);
        delete $OWNER{$self};
    }
}

*coordsystem = *Pixel::WCSc::Projections_coordsystem;
*find_region = *Pixel::WCSc::Projections_find_region;
*regions = *Pixel::WCSc::Projections_regions;
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


############# Class : Pixel::WCS::Projection ##############

package Pixel::WCS::Projection;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( Pixel::WCS );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = Pixel::WCSc::new_Projection(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        Pixel::WCSc::delete_Projection($self);
        delete $OWNER{$self};
    }
}

*name = *Pixel::WCSc::Projection_name;
*inside = *Pixel::WCSc::Projection_inside;
*border_distance = *Pixel::WCSc::Projection_border_distance;
*amin = *Pixel::WCSc::Projection_amin;
*amax = *Pixel::WCSc::Projection_amax;
*bmin = *Pixel::WCSc::Projection_bmin;
*bmax = *Pixel::WCSc::Projection_bmax;
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


############# Class : Pixel::WCS::projectionVector ##############

package Pixel::WCS::projectionVector;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( Pixel::WCS );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = Pixel::WCSc::new_projectionVector(@_);
    bless $self, $pkg if defined($self);
}

*size = *Pixel::WCSc::projectionVector_size;
*empty = *Pixel::WCSc::projectionVector_empty;
*clear = *Pixel::WCSc::projectionVector_clear;
*push = *Pixel::WCSc::projectionVector_push;
*pop = *Pixel::WCSc::projectionVector_pop;
*get = *Pixel::WCSc::projectionVector_get;
*set = *Pixel::WCSc::projectionVector_set;
sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        Pixel::WCSc::delete_projectionVector($self);
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

package Pixel::WCS;

1;
