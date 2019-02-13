# Common include for building the interpreter

OBJ = obj/$(ARCH)/aektest.o obj/$(ARCH)/host_machine.o obj/$(ARCH)/gvm_core.o obj/$(ARCH)/gvm_run.o

$(BIN): $(OBJ) Makefile_aek.$(MEXT)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(BIN)

obj/$(ARCH)/aektest.o: aektest.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

obj/$(ARCH)/host_machine.o: host_machine.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

obj/$(ARCH)/gvm_core.o: gvm_core.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

obj/$(ARCH)/gvm_run.o: gvm_run.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(TARGET) obj/$(ARCH)/*.o *~ core


