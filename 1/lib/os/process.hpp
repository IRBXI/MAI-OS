#include "pipe.hpp"

void CreateProcessWithPipesConnection(char *const program_name,
                                      Pipe &pipe_to_child,
                                      Pipe &pipe_from_child);
