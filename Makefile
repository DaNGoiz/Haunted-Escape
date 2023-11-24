# Compiler settings - Can be customized.
CXX = g++
CXXFLAGS = -Wall -g
LDFLAGS =

# Makefile settings - Can be customized.
APPNAME = game
EXT = .cpp
SRCDIR = .
OBJDIR = obj
BINDIR = bin

SOURCES := $(wildcard $(SRCDIR)/*$(EXT))
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)

# Define PHONY targets
.PHONY: all clean distclean

# Default target
all: $(BINDIR)/$(APPNAME)

# Linking
$(BINDIR)/$(APPNAME): $(OBJECTS) | $(BINDIR)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compilation
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# Clean up
clean:
	$(RM) $(OBJECTS)

distclean: clean
	$(RM) $(BINDIR)/$(APPNAME)

# Non-file targets
.PRECIOUS: $(OBJDIR)/. $(OBJDIR)%/.

# Directory creation for object files and binary
$(OBJDIR) $(BINDIR):
	mkdir -p $@
