#[cxx::bridge( namespace = "model::schema")]
pub mod ffi {

    #[namespace = "model::datatypes"]
    extern "C++" {
        include!("cxx-demo/src/model/datatypes.rs.h");
        type StructType = crate::model::datatypes::StructType;
    }

    #[derive(Serialize, Deserialize)]
    pub struct SchemaV2 {
        pub schema_id: i32,
        #[serde(flatten)]
        pub fields: StructType,
    }
}

pub use ffi::*;
