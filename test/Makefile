#
# filename : Makefile
# author   : huys
# updated  : 2008.11.21.
# version  : 0.1
#
#
TOPDIR = ..
#
include $(TOPDIR)/make.inc

#
SUBDIRS =        \
      adt        \
      funcptr    \
      factory    \
      nonthrow   \
      smartptr   \
      thintempl  \
      handlebody \
      exprtempl  \
      delegate   \
      observer   \
      builder    \
      objectpool \
      crtp       \
      composite  \
      command    \
      visitor    \
      state      \
      bridge     \
      proxy      \
      facade     \
      decorator  \
      flyweight  \
      iterator   \
      builder    \
      strategy   \
      mediator   \
      prototype  \
      adapter    \
      afactory   \
      interpreter\
      chainofresp\
      templmethod\
      template   \
      policies   \
      bntrick    \
      metafunc   \
      functor    \
      vtable     \
      event      \
      dispatch   \
      memento    \
      singleton  \
      dataalign  \
      
#
.PHONY: all
all:
	$(MAKEALL_SUBDIRS)

#
UDOC :
	cd $(DOCDIR) && $(MAKE)

install :

.PHONY: clean
clean:
	$(MAKECLEAN_SUBDIRS)

