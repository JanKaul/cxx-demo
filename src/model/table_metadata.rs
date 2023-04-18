#[cxx::bridge( namespace = "model::table_metadata")]
pub mod ffi {

    #[namespace = "model::schema"]
    extern "C++" {
        include!("cxx-demo/src/model/schema.rs.h");
        type SchemaV2 = crate::model::schema::SchemaV2;
    }

    #[derive(Serialize, Deserialize)]
    pub struct TableMetadataV2 {
        table_uuid: i64,
        schemas: Vec<SchemaV2>,
        current_schema_id: i32
    }
}

pub use ffi::*;
