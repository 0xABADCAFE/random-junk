# Common include for building the interpreter

OBJ = obj/$(ARCH)/test_interpreter.o obj/$(ARCH)/host_machine.o obj/$(ARCH)/gvm_core.o obj/$(ARCH)/gvm_run.o

$(BIN): $(OBJ) Makefile.$(MEXT)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(BIN)

obj/$(ARCH)/test_interpreter.o: test_interpreter.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

obj/$(ARCH)/host_machine.o: host_machine.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

obj/$(ARCH)/gvm_core.o: gvm_core.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

obj/$(ARCH)/gvm_run.o: gvm_run.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(TARGET) obj/$(ARCH)/*.o *~ core


