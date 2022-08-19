{
  description = "C++ implementation of a database";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (
      system:
        let
          pkgs = import nixpkgs { inherit system; };
          llvm = pkgs.llvmPackages_14;
          lib = nixpkgs.lib;

        in
          {
            devShell = llvm.stdenv.mkDerivation {
              name = "shell";
              buildInputs = [
                # builder
                # p.gnumake
                # p.bear
                pkgs.cmake  # for discovering libraries
                pkgs.pkg-config
                pkgs.meson
                pkgs.ninja
                # debugger
                # llvm.lldb
                pkgs.gdb

                pkgs.gtest
                pkgs.fmt
                pkgs.tl-expected
              ] ++ lib.optionals pkgs.stdenv.isLinux [ llvm.lld ]
              ;
              nativeBuildInputs = [
                pkgs.clang-tools_14  # don't use clangd from llvm.clang
              ];
              LD_LIBRARY_PATH = lib.strings.makeLibraryPath [ pkgs.fmt pkgs.gtest ];
            };
          }
    );
}
