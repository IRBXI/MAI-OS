#include "pipe.hpp"

namespace lib::os {

void CreateProcessWithPipesConnection(char *const program_name,
                                      Pipe &pipe_to_child,
                                      Pipe &pipe_from_child);

}
