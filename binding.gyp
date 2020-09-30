{
  "targets": [
    {
      "target_name": "mmap_binding",
      "type": "static_library"
      "sources": [ 
          "mmap.cc" 
          ],
      "conditions" : [
          ['OS == "linux"', {
              'sources!': [
              # Linux-only; exclude on other platforms.
              'mmap_linux.cc',
              ]
          }]
      ]
    }
  ]
}