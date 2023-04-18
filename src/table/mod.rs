use crate::model::{table_metadata::TableMetadataV2, schema::SchemaV2};

use self::transaction::Transaction;

pub mod transaction;

pub struct Table {
    metadata: TableMetadataV2
}

impl Table {
    fn schema(&self) -> &SchemaV2 {
        &self.metadata.schemas[self.metadata.current_schema_id as usize]
    }
    fn new_transaction(&self) -> Box<Transaction> {
        Box::new(Transaction {
            operations: Vec::new()
        })
    }
}

#[cxx::bridge( namespace = "table")]
pub mod ffi {

    #[namespace = "model::schema"]
    extern "C++" {
        include!("cxx-demo/src/model/schema.rs.h");
        type SchemaV2 = crate::model::schema::SchemaV2;
    }

    extern "Rust" {
        type Table;
        type Transaction;
        
        fn schema(self: &Table) -> &SchemaV2;

        fn new_transaction(self: &Table) -> Box<Transaction>;
    }
}