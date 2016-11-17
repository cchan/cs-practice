# Auto-dependency generation based on
# http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/

.DEFAULT_GOAL=all

CPP = g++
CPPFLAGS = -Og -g -DDEBUG -Wall -pedantic -std=gnu++11
LDFLAGS = 
SRC = $(wildcard *.cpp)
BUILDDIR = build
OBJ = $(addprefix $(BUILDDIR)/, $(SRC:.cpp=.o))
DEPDIR = $(BUILDDIR)/.depend
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td
EXECUTABLE = $(BUILDDIR)/datastructs

COMPILE.CPP = $(CPP) $(DEPFLAGS) $(CPPFLAGS) -c
POSTCOMPILE = mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d

$(shell mkdir -p $(BUILDDIR) >/dev/null)
$(shell mkdir -p $(DEPDIR) >/dev/null)

.PHONY: all
all: $(EXECUTABLE)

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)

# The executable depends on all of the .o files
$(EXECUTABLE): $(OBJ)
	$(CPP) $(LDFLAGS) -o $@ $^

# Each o file depends on its respective C++ file.
$(BUILDDIR)/%.o: %.cpp
$(BUILDDIR)/%.o: %.cpp $(DEPDIR)/%.d
	$(COMPILE.CPP) -o $@ $<
	$(POSTCOMPILE)

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

-include $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRCS)))
