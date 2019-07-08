import File
import Debug
import Shell

def root_dir(path = '.'):
    _path = path
    while not File.is_root(_path):
        if File.exists(_path + '/.projectile'):
            super_project = Shell.get(["git", "rev-parse", "--show-superproject-working-tree"])
            if super_project:
                return super_project
            return File.full_path(_path)
        _path = _path + "/.."
    Debug.throw("Git root directory not found for path: " + File.full_path(path))

def clone(link, destination, delete_existing = False, recursive = False):

    if (delete_existing):
        File.rm(destination)

    if (len(destination) > 0 and File.exists(destination)):
        Debug.throw("Git repository: " + link + " already exists for path: " + File.full_path(destination))

    command = ["git", "clone", link, destination]

    if recursive:
        command += ["--recursive"]
        
    Shell.run(command)

def has_changes(path):
    return len(Shell.get(["git", "-C", File.full_path(path), "status", "-s"])) != 0
