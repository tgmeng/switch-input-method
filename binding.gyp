{
  "targets": [
    {
      "target_name": "switch_input_method",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "src/main.cc" ],
      'include_dirs': ["<!(node -p \"require('node-addon-api').include_dir\")"],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      'conditions': [
        ['OS=="mac"', {
            'sources': [
                "src/switch_input_method_mac.mm"
            ],
            'libraries': [ '-framework Carbon' ]
        }],
        ['OS=="win"', {
            'sources': [
                "src/switch_input_method_win.cc"
            ]
        }]
      ]
    }
  ]
}