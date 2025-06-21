{
    "targets": [
        {
            "target_name": "napih-poc",
            "sources": [
                "src/Greeter.cpp",
                "src/napih-poc.cpp",
            ],
            "include_dirs": ["src/"],
            "dependencies": [
                "<!(node -p \"require('node-addon-api').targets\"):node_addon_api_except_all",
            ],
            "conditions": [
                [
                    'OS=="mac"',
                    {
                        "cflags+": ["-fvisibility=hidden"],
                        "xcode_settings": {
                            "GCC_SYMBOLS_PRIVATE_EXTERN": "YES",  # -fvisibility=hidden
                        },
                    },
                ]
            ],
        }
    ]
}
