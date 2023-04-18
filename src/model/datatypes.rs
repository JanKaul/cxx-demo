#[cxx::bridge( namespace = "model::datatypes")]
pub mod ffi {

    #[derive(Serialize, Deserialize)]
    pub enum Type {
        Boolean,
        Int,
        Long,
        Float,
        Double,
        Date,
        Time,
        Timestamp,
        Timestampz,
        String,
        Uuid,
        Fixed,
        Binary,
        Struct,
        List,
        Map
    }

    #[derive(Serialize, Deserialize)]
    pub struct StructType {
        pub fields: Vec<StructFieldType>,
    }

    #[derive(Serialize, Deserialize)]
    pub struct StructFieldType {
        pub id: i32,
        pub name: String,
        pub required: bool,
        #[serde(rename = "type")]
        pub field_type: Type,
    }
}

pub use ffi::*;
