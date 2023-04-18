fn main() {

    let files = vec!["src/model/schema.rs","src/model/datatypes.rs","src/model/table_metadata.rs","src/table/mod.rs"];

    cxx_build::bridges(files).compile("cxx-demo");
}
