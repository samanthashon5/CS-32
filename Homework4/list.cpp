void listAll(const File* f, string path)  // two-parameter overload
{
  if(f -> name() != "")
  {
    cout << path << "/" << f -> name() << endl;
  }

  if(f -> files() == nullptr || f -> files() -> size() == 0)
  {
    return;
  }

  if (f -> name() != "")
  {
    path += "/" + f -> name();
  }

  for(auto it = f -> files() -> begin(); it != f -> files() -> end(); it++)
    {
      listAll(*it, path);
    }
}
