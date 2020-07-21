from distutils.core import setup
import py2exe, sys, os

sys.argv.append('py2exe')
images = [('images', ['23Div.png', '23Div.ico'])]

setup(
 options = {"py2exe" : {'bundle_files':1,
                        'includes':['encodings','encodings.*', 'sip'],
                        'dll_excludes':["MSVCP90.dll"]}
           },
 windows = [{'script': "RDC_x86.py",
            "icon_resources" : [(1,"23Div.ico")]
            }
           ],
 data_files = images,
 zipfile = None,
)
# python setup.py py2exe --includes sip
