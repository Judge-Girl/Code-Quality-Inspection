
import os
import subprocess

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML


def get_dump_result(path):
    subprocess.run(['cppcheck', path, '--dump'], stdout=subprocess.PIPE)

    dump_file_path = os.path.join(f'{path}.dump')
    dump_content = ''.join(open(dump_file_path, "r").readlines())
    
    os.remove(dump_file_path)

    return dump_content


def coding_style_analyzer(path):
    xml = XML.fromstring(get_dump_result(path))
    return None
